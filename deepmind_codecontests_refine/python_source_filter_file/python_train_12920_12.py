def is_correct(s):
    return bool(
        [i for i in s if 'a' <= i <= 'z'] and
        [i for i in s if 'A' <= i <= 'z'] and
        [i for i in s if '0' <= i <= '1']
    )

n = int(input())
ans = []

def gen_one(s):
    for i in range(len(s)):
        for j in ('0', 'a', 'A'):
            new_pass = s[:i] + j + s[i+1:]
            if (is_correct(new_pass)):
                return new_pass
    return None

for i in range(n):
    password = input()
    if is_correct(password):
        ans.append(password)
        continue
    a = gen_one(password)
    if a:
        ans.append(a)
        continue

    if 'a' <= password[2] <= 'z':
        ans.append('A1' + password[2:])
        continue
    if 'A' <= password[2] <= 'Z':
        ans.append('a1' + password[2:])
        continue
    if '0' <= password[2] <= '9':
        ans.append('Aa' + password[2:])
        continue

for i in ans:
    print(i)
