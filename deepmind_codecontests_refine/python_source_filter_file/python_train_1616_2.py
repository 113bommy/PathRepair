n = int(input())
a = input().split()

def is_pow(s) :
    if s[0]!="1" : return False
    for i in range(1,len(s)) :
        if s[i]!="0" : return False
    return True

ans = ""
zeroes = 0
for s in a :
    if s=="0" :
        print(0)
        exit(0) 
    if not is_pow(s) : ans = s
    else : zeroes+=len(s)-1
print(ans+"0"*zeroes)