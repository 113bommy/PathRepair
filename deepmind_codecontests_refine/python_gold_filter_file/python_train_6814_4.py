A = int(input());
start = (45*10**18*19+1)%A;
start = A-start;
print(start+1, start+10**19);
