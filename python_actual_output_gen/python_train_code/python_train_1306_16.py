n,t = map(int,input().split())
l = input()
while t:
    l.replace("BG", "GB")
    t -= 1
print(l)