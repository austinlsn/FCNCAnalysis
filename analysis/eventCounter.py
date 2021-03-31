import glob
import tqdm

VERSION = "fcnc_v2"
BABY_DIR = "/hadoop/cms/store/user/ksalyer/FCNC_NanoSkim/{}".format(VERSION)
N_EVENTS_DIR = "./n_events"

sample_dirs = glob.glob(BABY_DIR+"/*")

for sample_dir in tqdm.tqdm(sample_dirs):
    n_events_files = glob.glob(sample_dir+"/output_*_nevents.txt")
    n_total_events = 0
    n_effective_events = 0
    for n_events_file in n_events_files:
        counted_total = False
        counted_effective = False
        with open(n_events_file, "r") as f_in:
            for line in f_in.readlines():
                line = line.split("\n")[0]
                if unicode(line, "utf-8").isnumeric():
                    if not counted_total:
                        n_total_events += int(line)
                        counted_total = True
                    elif not counted_effective:
                        n_effective_events += int(line)
                        counted_effective = True
                if counted_total and counted_effective:
                    break
            if not counted_total or not counted_effective:
                print(f_in.readlines())
    sample = sample_dir.split("/")[-1]
    with open(N_EVENTS_DIR+"/"+sample+"_n_events.txt", "w") as f_out:
        f_out.write(str(n_total_events)+"\n")
        f_out.write(str(n_effective_events)+"\n")