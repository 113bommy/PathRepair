s=set(range(1,int(input())+1))
s1=set(int(x) for x in input().split())|set(int(x) for x in input().split())
print('I become the guy.' if s==s1 else 'Oh, my keyboard!')
