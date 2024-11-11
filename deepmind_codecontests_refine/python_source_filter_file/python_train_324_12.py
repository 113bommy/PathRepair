n = int(input())
a = [int(i) for i in input().split()]
ch = [i for i in a if i % 2 == 0]
nch = [i for i in a if i % 2 == 1]
if len(ch) == len(nch):
    print(0)
else:
    if len(ch) > len(nch):
        s = sum(ch[:len(ch)-len(nch)-1])
    else:
        s = sum(nch[:len(nch)-len(ch)-1])
    print(s)
