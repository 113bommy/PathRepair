S=int(input())
h=S//60//60
m=S%3600//60
s=S%60%60%60

print(f"{h}:{m}:{s}")
