# -*- coding: utf-8 -*-


def main(_text: str):
    print(_text.upper())


while True:
    try:
        text = input()
    except:
        break

    main(text)