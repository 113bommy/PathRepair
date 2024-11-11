n = int(input())
o1,o2 = map(int,input().split())
s1,s2 = map(int,input().split())
t1,t2 = map(int,input().split())
a1,a2,a3=o1,s1,t1
sum = o1+t1+s1
if sum==n:
    print(a1,a2,a3)
else:
    remain = n-sum
    if o2-o1<remain:
        a1=o2
        remain = remain - (o2-o1)
        if s2-s1<remain:
            a2=s2
            remain = remain - (s2-s1)
            if t2-t1<remain:
                a3=t2
            else:
                a3+=remain
        else:
            a2+=remain
    else:
        a1+=remain
    print(a1,a2,a3)
