from string import ascii_letters

mirror_symmetry = 'AHIMOoTUVvWwXxY'

symmetric_to = {
    'b': 'd',
    'd': 'b',
    'p': 'q',
    'q': 'p',
}

others = set(ascii_letters) - set(mirror_symmetry + 'bdpq')

string = input()


def f(s):
    if set(s) & others:
        return 'NIE'
    if len(s) % 2 == 1:
        if s[len(s) // 2] not in mirror_symmetry:
            return 'NIE'
        s = s[:len(s) // 2] + s[len(s) // 2 + 1:]
    for i in range(len(s) // 2):
        if s[i] in mirror_symmetry and s[-1 - i] == s[i]:
            continue
        if s[i] in symmetric_to and symmetric_to[s[i]] == s[-1 - i]:
            continue
        return 'NIE'
    return 'TAK'

print(f(string))
