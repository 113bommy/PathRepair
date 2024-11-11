s = input()
l = []
n = len(s)
while(n):
    n -= 1;
    if(s not in l):
        l.append(s)
    s = s[-1] + s[:len(s)-1]
print(len(l))