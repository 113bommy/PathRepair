def no():
    print("NO")
def yes():
    print("YES")
def check(s):
    for i in range(len(s)-11):
        if s[i] == '8':
            return True
    return False
I = int(input())
for i in range(I):
    l = int(input())
    s = str(input())
    found_idx = s.find('8')
    if found_idx > -1 and l - found_idx  >= 10:
        yes()
    else:
        no()
