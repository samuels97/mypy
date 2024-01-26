ynames = lines[2].split()

y ={}
for name in ynames:
  y[name] = []

#data from the rest of the lines
for line in lines[3:]:
  yvalues = [float(x) for x in line.split()]
  if len(yvalues) == 0: continue
  i = 0 #counter for yvalues
  for name in ynames:
    y[name].append(yvalues[i]); I += 1
