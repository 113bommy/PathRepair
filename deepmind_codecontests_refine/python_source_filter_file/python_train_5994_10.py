s = input()
l = []
n = len(s)
while(n):
    n -= 1;
    if(s not in l):
        l.append(s)
    s = s[-1] + s[:n- 1]
print(len(l))