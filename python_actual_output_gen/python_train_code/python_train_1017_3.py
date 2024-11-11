S = input()
ans = min(max(map(len, S.split(c)))
          for c in [chr(i + 97) for i in range(26)]
          if c not in S)
print(ans)