
e = [
    {'B', 'C', 'F', 'H', 'I', 'K', 'N', 'O', 'P', 'S', 'U', 'V', 'W', 'Y'},
    {'AC', 'AG', 'AL', 'AM', 'AR', 'AS', 'AT', 'AU', 'BA', 'BE', 'BH', 'BI', 'BK', 'BR', 'CA', 'CD', 'CE', 'CF', 'CL', 'CM', 'CN', 'CO', 'CR', 'CS', 'CU', 'DB', 'DS', 'DY', 'ER', 'ES', 'EU', 'FE', 'FL', 'FM', 'FR', 'GA', 'GD', 'GE', 'HE', 'HF', 'HG', 'HO', 'HS', 'IN', 'IR', 'KR', 'LA', 'LI', 'LR', 'LU', 'LV', 'MC', 'MD', 'MG', 'MN', 'MO', 'MT', 'NA', 'NB', 'ND', 'NE', 'NH', 'NI', 'NO', 'NP', 'OG', 'OS', 'PA', 'PB', 'PD', 'PM', 'PO', 'PR', 'PT', 'PU', 'RA', 'RB', 'RE', 'RF', 'RG', 'RH', 'RN', 'RU', 'SB', 'SC', 'SE', 'SG', 'SI', 'SM', 'SN', 'SR', 'TA', 'TB', 'TC', 'TE', 'TH', 'TI', 'TL', 'TM', 'TS', 'XE', 'YB', 'ZN', 'ZR'},
    {},
]

s = input()
n = len(s)
d = [0 for _ in range(n)]
for i in range(n):
    for l in range(0, 3):
        if i-l > 0 and s[i-l:i+1] in e[l]:
            if l == 0 or d[i-l]:
                d[i] = 1
                break

print('YES' if d[n-1] else 'NO')
