n,m=map(int,input().split())
a=set()
for i in range(n):
    b=input().split()
    a.update(b)
if len(a)==3 and 'W' in a and 'B' in a and 'G' in a or len(a)==2 and (('W' in a and 'B') or ('W' in a and 'G' in a) or ('G' in a and 'B' in a)) or len(a)==1 and ('W' in a or 'B' in a or 'G' in a):
    print('#Black&White')
else:
    print('#Color')