s = input()

s.replace(' ','')

last = s[len(s) - 2].lower()

if last in ['a','e','i','o','u','y']:
    print("Yes")
else:
    print("No")