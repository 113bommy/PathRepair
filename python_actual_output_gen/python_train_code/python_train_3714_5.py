s = input()
ints = [ord(i) - ord('a') for i in s]
K = int(input())
n = len(s)
i = 0
while i < n:
    if ints[i] != 0 and 25 - ints[i] + 1 <= K:
        K -= 25 - ints[i] + 1
        ints[i] = 0
    i += 1

K %= 26
ints[-1] = (ints[-1] + K) % 26
s_ = ''
for i in ints:
    s_ += chr(i + ord('a'))

print(s_, K)
