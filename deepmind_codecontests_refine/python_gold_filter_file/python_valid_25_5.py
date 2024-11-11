I=input
exec(int(I())*"s=I();t=I();print('NYOE S'[any(t in s[:i]+s[i::-1]for i in range(len(s)))::2]);")