def f(c):
    return ord(c) - ord('a')
def main():
    s = input() + '#'
    k = [0 for i in range(26)]
    w = [0 for i in range(26)]
    for i in range(len(s)):
        for j in range(26):
            if s[i] == '#' or f(s[i]) == j:
                k[j] = max(k[j], w[j])
                w[j] = 1
            else:
                w[j] += 1
    print(min(*k))
main()