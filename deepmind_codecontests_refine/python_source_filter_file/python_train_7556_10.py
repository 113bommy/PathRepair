n = int(input())
if n<10:
    print(n+1)
else:
    tp = str(n)
    l1 = str(int(tp[0])+1)+('0'*(len(tp)-1))
    print(int(l1)-n)