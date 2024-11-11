def calc_degrees(n):
    ds = [1 for i in range(n + 1)]
    for i in range(1, n + 1):
        ds[i] = ds[i - 1] * PRIME
    return ds


def calc_hashes(s):
    hs = [0 for i in range(len(s) + 1)]
    for i in range(1, len(s) + 1):
        hs[i] = (hs[i - 1]*PRIME + ord(s[i - 1])) % MOD
    return hs


def get_hash(l, r, hs):
    if l > r:
        return 0
    #print('l:', l, 'r:', r, 'hashes:', hs)
    return (hs[r + 1] - degrees[r - l + 1]*hs[l]) % MOD


def find_max_common_prefix(hs1, hs2):
    l = 0
    r = len(hs1) - 2 if len(hs1) < len(hs2) else len(hs2) - 2
    while l < r - 1:
        m = (l + r) // 2
        if get_hash(0, m, hs1) == get_hash(0, m, hs2):
            l = m
        else:
            r = m
    #print('l:', l, 'r:', r)
    if get_hash(0, r, hs1) == get_hash(0, r, hs2):
        return r + 1
    elif get_hash(0, l, hs1) == get_hash(0, l, hs2):
        return l + 1
    else:
        return 0


def find_max_common_suffix(hs1, hs2):
    l = 0
    r = len(hs2) - 2
    n = r
    while l < r - 1:
        m = (l + r) // 2
        if get_hash(m + 1, n + 1, hs1) == get_hash(m, n, hs2):
            r = m
        else:
            l = m
    if get_hash(l + 1, n + 1, hs1) == get_hash(l, n, hs2):
        return n + 1 - l
    elif get_hash(r + 1, n + 1, hs1) == get_hash(r, n, hs2):
        return n + 1 - r
    else:
        return 0


def find_extra_indexes(n, whs, dhs):
    """extra_inds = []
    
    for i in range(n):
        if get_hash(0, i - 1, whs) == get_hash(0, i - 1, dhs) and\
                get_hash(i + 1, n - 1, whs) == get_hash(i, n - 2, dhs):
            extra_inds.append(i + 1)
    return extra_inds
    """
    extra_inds = []
    max_prefix_len = find_max_common_prefix(whs, dhs)
    max_suffix_len = find_max_common_suffix(whs, dhs)
    if max_prefix_len + max_suffix_len + 1 == n:
        extra_inds.append(max_prefix_len + 1)
    elif max_prefix_len + max_suffix_len + 1 > n:
        for i in range(n - max_suffix_len - 1, max_prefix_len + 1):
            extra_inds.append(i + 1)
    return extra_inds


def find_max_common_prefix_stupid(s1, s2):
    prefix_len = 0
    i = 0
    while i < len(s2) and s1[i] == s2[i]:
        prefix_len += 1
        i += 1
    print('pref len:', prefix_len)
    return prefix_len


def find_max_common_suffix_stupid(s1, s2):
    suffix_len = 0
    i = len(s1) - 1
    while i >= 1 and s1[i] == s2[i - 1]:
        suffix_len += 1
        i -= 1
    print('suf len:', suffix_len)
    return suffix_len


def find_extra_inds_stupid(s1, s2):
    extra_inds = []
    n = len(s1)
    max_prefix = find_max_common_prefix_stupid(s1, s2)
    max_suffix = find_max_common_suffix_stupid(s1, s2)
    if max_prefix + max_suffix + 1 == n:
        extra_inds.append(max_prefix + 1)
    elif max_prefix + max_suffix + 1 > n:
        for i in range(n - max_suffix - 1, max_prefix + 1):
            extra_inds.append(i + 1)
    return extra_inds
# aaaabbb
# aaa bbb
# aaabbbb
# aaabbb


PRIME = 29
MOD = 2 << 15

s1 = input()
#degrees = calc_degrees(len(s))
#wrong_hashes = calc_hashes(s)

s2 = input()
#dict_hashes = calc_hashes(s)

#extra_indexes = find_extra_indexes(len(s) + 1, wrong_hashes, dict_hashes)
extra_indexes = find_extra_inds_stupid(s1, s2)
print(len(extra_indexes))
print(" ".join(map(str, extra_indexes)))
# aaaaaaabaaaaa 7, 5 (13)
# aaaaaaaaaaaa

# aaaabbb
# aaa bbb
# aaabbbb
# aaabbb
# abcdefgh
# abc efgh

# m c p: abc (l - ind) len: 3
# m c s: efgh (r - ind) len: 4
# len_pr + len suf + 1 >= len s
