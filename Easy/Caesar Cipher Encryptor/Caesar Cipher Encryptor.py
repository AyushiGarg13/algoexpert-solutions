def caesarCipherEncryptor(string, key):
    output = []
    key = key % 26
    for char in string:
        val = ord(char) + key
        val = val-26 if val > 122 else val
        output.append(chr(val))

    return "".join(output)
