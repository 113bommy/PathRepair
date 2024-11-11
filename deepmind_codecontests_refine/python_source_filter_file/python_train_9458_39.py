S = input().replace('eraser', '').replace('dreamer', '')
chk = S.replace('erase', '').replace('dream', '')
print(['YES', 'NO'][len(chk) > 0])