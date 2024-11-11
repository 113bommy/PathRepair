import sys
read = []
for line in sys.stdin:
    read.append(line)
var = False
for elem in read:
    if elem == 'H' or elem == 'Q' or elem == '9':
        var = True
if var:
    print("YES")
else:
    print("NO")
