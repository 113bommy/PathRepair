import sys 
line_list = sys.stdin.readline().rstrip().split('+')
line_list = [int(x) for x in line_list]
line_list.sort()
out = ""
for item in range(len(line_list)):
  if item != len(line_list):
    out += str(line_list[item]) + "+"
  else:
    out += str(line_list[item])
sys.stdout.write(out)