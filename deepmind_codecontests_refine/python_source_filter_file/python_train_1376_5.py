# suffix three
n=int(input())
for i in range(n):
    s=str(input())
    if(s.endswith('po')):
        print("FILIPINO")
    if(s.endswith('masu') or s.endswith('desu')):
        print("JAPANESE")
    if(s.endswith('mnnida')):
        print("KOREAN")    