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

def load_data(filename):
  f = open(filename, 'r'); lines = f.readlines(); f.close()
  dt = float(lines[1])
  ynames = lines[2].split()
  y = {}
  for name in ynames:
    y[name] = []
    
  for line in lines[3:]:
    yvalues = [float(yi) for yi in line.split()]
    if len(yvalues) == 0: continue #skip blank lines
    for name, value in zip(ynames, yvalues):
      y[name].append(value)
  return y, dt
