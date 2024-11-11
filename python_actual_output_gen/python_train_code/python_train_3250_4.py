from sys import stdin


n, k = (int(x) for x in stdin.readline().split())

passwords = []

for _ in range(n):
    passwords.append(stdin.readline().strip())

right_password = stdin.readline().strip()

length_less_than_password = len([password for password in passwords if len(password) < len(right_password)])
length_less_than_or_equal_to_password = len([password for password in passwords if len(password) <= len(right_password)])

a = length_less_than_password // k

spent = length_less_than_password + a * 5

print(spent + 1, end=' ')

a = length_less_than_or_equal_to_password // k

spent = length_less_than_or_equal_to_password + a * 5

print(spent)
