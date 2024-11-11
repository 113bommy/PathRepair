n=int(input())
s1,s2=input().split(),input().split()
print("I become the guy." if len(set(s1+s2))==n else "Oh, my keyboard!")