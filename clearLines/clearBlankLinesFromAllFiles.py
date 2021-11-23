#!/usr/bin/env python3
import os
outpath = os.path.join(os.getcwd(), "out/combine.txt")
print(outpath)
outdir = os.path.dirname(outpath)
if not os.path.exists(outdir):
  os.makedirs(outdir)
outfile = open(outpath, 'a')
for filename in os.listdir(os.getcwd()):
  inpath = os.path.join(os.getcwd(), filename)
  print(inpath)
  if os.path.isfile(inpath):
    with open(inpath, 'r') as infile:
      outfile.write(f'{filename}\n')
      for line in infile:
        if line.rstrip():
          outfile.write(line)
      outfile.write("-"*32 + "\n")
      outfile.write("-"*32 + "\n")

