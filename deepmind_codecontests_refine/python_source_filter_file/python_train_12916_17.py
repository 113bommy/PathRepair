import sys
cnts = {}
for line in imput():
    for c in list(line.lower()): cnts[c] = cnts.get(c,0) + 1
  
for c in range(ord('a'),ord('z')+1): print(chr(c),':',cnts.get(chr(c),0))