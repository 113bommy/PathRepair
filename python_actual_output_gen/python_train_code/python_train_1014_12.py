S = input()
odd = S[1::2]
even = S[::2]
print(min(odd.count("1") + even.count("0"), even.count("0") + odd.count("1")))