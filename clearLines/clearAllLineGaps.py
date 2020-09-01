infile = open("a.txt", "r")
outfile = open("b.txt", "w")
for line in infile:
  if not line.strip(): continue  # skip the empty line
  outfile.write(line)  # non-empty line. Write it to output
infile.close()
outfile.close()