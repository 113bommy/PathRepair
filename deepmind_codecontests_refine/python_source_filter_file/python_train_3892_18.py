s = list(input())
import collections
c = collections.Counter(s)
print("First" if sum(v&1 for v in c.values())&1 and sum(v&1 for v in c.values()) != 0 else "Second")