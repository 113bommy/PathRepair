import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7


# MOD = 998244353


class KMP:
    def __init__(self, needle):
        """
        https://ja.wikipedia.org/wiki/クヌース–モリス–プラット法
        :param typing.Sequence needle: 何を検索するか
        """
        self._needle = needle
        kmp = [0] * (len(needle) + 2)
        kmp[0] = -1
        kmp[1] = 0
        i = 2
        j = 0
        while i < len(needle):
            if needle[i - 1] == needle[j]:
                kmp[i] = j + 1
                i += 1
                j += 1
            elif j > 0:
                j = kmp[j]
            else:
                kmp[i] = 0
                i += 1
        self._kmp = kmp

    def index_of(self, haystack, m=0, i=0):
        """
        haystack の何番目に needle があるか。見つからなければ -1
        :param typing.Sequence haystack: 何から検索するか
        :param int m: The position of the current character in haystack
        :param int i: The position of the current character in needle
        :rtype: int
        """
        while m + i < len(haystack):
            if self._needle[i] == haystack[m + i]:
                i += 1
                if i == len(self._needle):
                    return m
            else:
                m += i - self._kmp[i]
                if i > 0:
                    i = self._kmp[i]
        return -1

    def search(self, haystack):
        """
        ret[i]: haystack[i:i+len(needle)] == needle
        :param typing.Sequence haystack: 何から検索するか
        :rtype: list of bool
        """
        ret = [False] * len(haystack)
        m = 0
        i = 0
        while m + i < len(haystack):
            m = self.index_of(haystack, m=m, i=i)
            if m < 0:
                break
            ret[m] = True
            m += len(self._needle) - self._kmp[len(self._needle) - 1] - 1
            i = max(0, self._kmp[len(self._needle) - 1])
        return ret


def test(t, s):
    ret = []
    for i in range(len(s)):
        ret.append(s[i:i + len(t)] == t)
    return ret


S = sys.stdin.buffer.readline().decode().rstrip()
T = sys.stdin.buffer.readline().decode().rstrip()

# kmp = KMP(T)
# print(kmp.search(S))

while len(S) < len(T) * 4:
    S *= 2

kmp = KMP(T)
idx = kmp.search(S)
ans = 0
for k in range(len(T)):
    i = k
    cnt = 0
    while i < len(idx):
        if idx[i]:
            cnt += 1
        else:
            ans = max(cnt, ans)
            cnt = 0
        i += len(T)
    ans = max(cnt, ans)
if len(T) * ans > len(S) // 4 * 3:
    print(-1)
else:
    print(ans)
