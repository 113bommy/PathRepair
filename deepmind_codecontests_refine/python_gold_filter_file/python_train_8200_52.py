n=int(input())
a=list(map(int,input().split()))
print ('YES' if len(a)==len(set(a)) else 'NO')
