s=input().strip()
if '4' not in s and '7' not in s:
    print(-1)
else:
    one=s.count('4')
    two=s.count('7')
    if one>=two:
        print(one)
    else:
        print(two)