#!/usr/bin/env python3
s={c:list(input()) for c in "abc"}
s="a"
while s[s]:s=s[s].pop(0)
print(s.upper())