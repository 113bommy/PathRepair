n=int(input())
s=input()
while len(s)<n:
    s=s[:n]+"..."
print(s)  