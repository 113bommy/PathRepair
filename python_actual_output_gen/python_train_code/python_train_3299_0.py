a,b=map(int,input())
print(sum(i==i[::-1] for i in map(str,range(a,b+1))))