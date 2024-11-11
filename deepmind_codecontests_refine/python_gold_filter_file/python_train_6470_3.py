n  = int(input())
s = input()
e = s[:n-10].count("8")
x = (n-11)//2
if(e>x):
    print("YES")
else:
    print("NO")