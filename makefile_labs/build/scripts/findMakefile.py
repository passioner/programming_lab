import os
import sys

def searchDirectory(directory, target, exclude_dirs):
    run_dir = os.getcwd()
    run_path = run_dir + '/' + directory
    skip = False
    #  for root, subFolders, files in os.walk(run_path):
    for root, subFolders, files in os.walk(directory):
        skip = False
        for i in range(len(exclude_dirs)):
            if directory in exclude_dirs[i]:
                skip = True
                break
        if not skip:
            for filename in files:
                if filename == target:
                    print(root + '/' + filename)

def findMakefile(args):
    exclude_dirs = []
    exclude_flag = 0
    target = args[-1]

    for i in range(1, len(args) - 1):
        if args[i] == '--exclude_dirs':
            exclude_flag = 1
            continue
        if exclude_flag == 1:
            exclude_dirs.append(args[i])
            exclude_flag = 0
            continue
        searchDirectory(args[i], target, exclude_dirs)


def main(args):
    findMakefile(args)

if __name__ == "__main__":
    main(sys.argv)
