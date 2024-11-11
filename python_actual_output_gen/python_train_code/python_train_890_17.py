import re
address = input()
address = re.sub('(http|ftp)(\w+?)(ru)', r'\1://\2.\3', address)
if re.match('.+?ru(\w+)', address):
    address = re.sub('ru(\w+)', r'ru/\1', address)
print(address)
