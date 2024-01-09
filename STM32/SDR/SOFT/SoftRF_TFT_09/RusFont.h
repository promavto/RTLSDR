// Adafruit GFX font RusFont size: 8x16

const uint8_t RusFontBitmaps[] PROGMEM = {
  0x7E,0x81,0xA5,0x81,0x81,0xBD,0x99,0x81,0x81,0x7E,	// SOH
  0x7E,0xFF,0xDB,0xFF,0xFF,0xC3,0xE7,0xFF,0xFF,0x7E,	// STX
  0x6D,0xFF,0xFF,0xFF,0xEF,0x8E,0x08,	// ETX
  0x10,0x71,0xF7,0xF7,0xC7,0x04,0x00,	// EOT
  0x18,0x3C,0x3C,0xE7,0xE7,0xE7,0x99,0x18,0x3C,	// ENQ
  0x18,0x3C,0x7E,0xFF,0xFF,0x7E,0x18,0x18,0x3C,	// ACK
  0x6F,0xF6,	// BEL
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE7,0xC3,0xC3,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,	// BS
  0x7B,0x38,0x61,0xCD,0xE0,	// TAB
  0xFF,0xFF,0xFF,0xFF,0xFF,0xC3,0x99,0xBD,0xBD,0x99,0xC3,0xFF,0xFF,0xFF,0xFF,0xFF,	// LF
  0x1E,0x1C,0x69,0x97,0x99,0xB3,0x66,0xCC,0xF0,	// VT
  0x7B,0x3C,0xF3,0xCD,0xE3,0x3F,0x30,0xC0,	// FF
  0x3F,0x33,0x3F,0x30,0x30,0x30,0x30,0x70,0xF0,0xE0,	// CR
  0x7F,0x63,0x7F,0x63,0x63,0x63,0x63,0x67,0xE7,0xE6,0xC0,	// SO
  0x18,0x18,0xDB,0x3C,0xE7,0x3C,0xDB,0x18,0x18,	// SI
  0x81,0x83,0x87,0x8F,0x9F,0xFE,0x78,0xE1,0x82,0x00,	// DLE
  0x02,0x0C,0x38,0xF3,0xFF,0xCF,0x8F,0x0E,0x0C,0x08,	// DC1
  0x31,0xEF,0xCC,0x30,0xC3,0x3F,0x78,0xC0,	// DC2
  0xCF,0x3C,0xF3,0xCF,0x3C,0xC0,0xCF,0x30,	// DC3
  0x7F,0xDB,0xDB,0xDB,0x7B,0x1B,0x1B,0x1B,0x1B,0x1B,	// DC4
  0x7D,0x8D,0x81,0xC6,0xD8,0xF1,0xB6,0x38,0x1B,0x1B,0xE0,	// NAK
  0xFF,0xFF,0xFF,0xF0,	// SYN
  0x31,0xEF,0xCC,0x30,0xC3,0x3F,0x78,0xCF,0xC0,	// ETB
  0x31,0xEF,0xCC,0x30,0xC3,0x0C,0x30,0xC0,	// CAN
  0x30,0xC3,0x0C,0x30,0xC3,0x3F,0x78,0xC0,	// EM
  0x18,0x1B,0xF8,0x61,0x80,	// SUB
  0x30,0xC3,0xFB,0x03,0x00,	// ESC
  0xC1,0x83,0x06,0x0F,0xE0,	// FS
  0x28,0xDB,0xFB,0x62,0x80,	// GS
  0x10,0x70,0xE3,0xE7,0xDF,0xFF,0x80,	// RS
  0xFF,0xFD,0xF3,0xE3,0x87,0x04,0x00,	// US
  0x6F,0xFF,0x66,0x60,0x66,	// symbol '!'
  0xCF,0x3C,0xD2,	// symbol
  0x6C,0xDB,0xFB,0x66,0xCD,0xBF,0xB6,0x6C,	// symbol '#'
  0x18,0x31,0xF6,0x3C,0x38,0x1F,0x03,0x87,0x8D,0xF0,0xC1,0x80,	// symbol '$'
  0xC3,0x8C,0x30,0xC3,0x0C,0x31,0xC3,	// symbol '%'
  0x38,0xD9,0xB1,0xC7,0x7B,0xB3,0x66,0xCC,0xEC,	// symbol '&'
  0x6D,0xE0,	// symbol '''
  0x36,0xCC,0xCC,0xCC,0x63,	// symbol '('
  0xC6,0x33,0x33,0x33,0x6C,	// symbol ')'
  0x66,0x3C,0xFF,0x3C,0x66,	// symbol '*'
  0x30,0xCF,0xCC,0x30,	// symbol '+'
  0x6D,0xE0,	// symbol ','
  0xFE,	// symbol '-'
  0xF0,	// symbol '.'
  0x02,0x0C,0x30,0xC3,0x0C,0x30,0x40,	// symbol '/'
  0x7D,0x8F,0x1E,0x7D,0x7A,0xF9,0xE3,0xC6,0xF8,	// digit '0'
  0x31,0xCF,0x0C,0x30,0xC3,0x0C,0x33,0xF0,	// digit '1'
  0x7D,0x8C,0x18,0x61,0x86,0x18,0x60,0xC7,0xFC,	// digit '2'
  0x7D,0x8C,0x18,0x33,0xC0,0xC1,0x83,0xC6,0xF8,	// digit '3'
  0x0C,0x38,0xF3,0x6C,0xDF,0xC3,0x06,0x0C,0x3C,	// digit '4'
  0xFF,0x83,0x06,0x0F,0xC1,0xC1,0x83,0xC6,0xF8,	// digit '5'
  0x38,0xC3,0x06,0x0F,0xD8,0xF1,0xE3,0xC6,0xF8,	// digit '6'
  0xFF,0x8C,0x18,0x30,0xC3,0x0C,0x18,0x30,0x60,	// digit '7'
  0x7D,0x8F,0x1E,0x37,0xD8,0xF1,0xE3,0xC6,0xF8,	// digit '8'
  0x7D,0x8F,0x1E,0x37,0xE0,0xC1,0x83,0x0C,0xF0,	// digit '9'
  0xF0,0x3C,	// symbol ':'
  0x6C,0x00,0xDE,	// symbol ';'
  0x0C,0x63,0x18,0xC1,0x83,0x06,0x0C,	// symbol '<'
  0xFE,0x00,0x07,0xF0,	// symbol '='
  0xC1,0x83,0x06,0x0C,0x63,0x18,0xC0,	// symbol '>'
  0x7D,0x8F,0x18,0x61,0x83,0x06,0x00,0x18,0x30,	// symbol '?'
  0x7D,0x8F,0x1E,0xFD,0xFB,0xF7,0x60,0x7C,	// symbol '@'
  0x10,0x71,0xB6,0x3C,0x7F,0xF1,0xE3,0xC7,0x8C,	// eng 'A'
  0xFC,0xCD,0x9B,0x37,0xCC,0xD9,0xB3,0x67,0xF8,	// eng 'B'
  0x3C,0xCF,0x0E,0x0C,0x18,0x30,0x61,0x66,0x78,	// eng 'C'
  0xF8,0xD9,0x9B,0x36,0x6C,0xD9,0xB3,0x6D,0xF0,	// eng 'D'
  0xFE,0xCD,0x8B,0x47,0x8D,0x18,0x31,0x67,0xFC,	// eng 'E'
  0xFE,0xCD,0x8B,0x47,0x8D,0x18,0x30,0x61,0xE0,	// eng 'F'
  0x3C,0xCF,0x0E,0x0C,0x1B,0xF1,0xE3,0x66,0x74,	// eng 'G'
  0xC7,0x8F,0x1E,0x3F,0xF8,0xF1,0xE3,0xC7,0x8C,	// eng 'H'
  0xF6,0x66,0x66,0x66,0x6F,	// eng 'I'
  0x1E,0x18,0x30,0x60,0xC1,0xB3,0x66,0xCC,0xF0,	// eng 'J'
  0xE6,0xCD,0xB3,0x67,0x8F,0x1B,0x33,0x67,0xCC,	// eng 'K'
  0xF0,0xC1,0x83,0x06,0x0C,0x18,0x31,0x67,0xFC,	// eng 'L'
  0xC7,0xDF,0xFF,0xFD,0x78,0xF1,0xE3,0xC7,0x8C,	// eng 'M'
  0xC7,0xCF,0xDF,0xFD,0xF9,0xF1,0xE3,0xC7,0x8C,	// eng 'N'
  0x38,0xDB,0x1E,0x3C,0x78,0xF1,0xE3,0x6C,0x70,	// eng 'O'
  0xFC,0xCD,0x9B,0x37,0xCC,0x18,0x30,0x61,0xE0,	// eng 'P'
  0x7D,0x8F,0x1E,0x3C,0x78,0xF1,0xEB,0xDE,0xF8,0x30,0x70,	// eng 'Q'
  0xFC,0xCD,0x9B,0x37,0xCD,0x99,0xB3,0x67,0xCC,	// eng 'R'
  0x7D,0x8F,0x1B,0x03,0x81,0x81,0xE3,0xC6,0xF8,	// eng 'S'
  0xFF,0xFB,0x4C,0x30,0xC3,0x0C,0x31,0xE0,	// eng 'T'
  0xC7,0x8F,0x1E,0x3C,0x78,0xF1,0xE3,0xC6,0xF8,	// eng 'U'
  0xC7,0x8F,0x1E,0x3C,0x78,0xF1,0xB6,0x38,0x20,	// eng 'V'
  0xC7,0x8F,0x1E,0x3C,0x7A,0xF5,0xFF,0x6C,0xD8,	// eng 'W'
  0xC7,0x8D,0xB3,0x63,0x87,0x1B,0x36,0xC7,0x8C,	// eng 'X'
  0xCF,0x3C,0xF3,0x78,0xC3,0x0C,0x31,0xE0,	// eng 'Y'
  0xFF,0x8E,0x18,0x61,0x86,0x18,0x61,0xC7,0xFC,	// eng 'Z'
  0xFC,0xCC,0xCC,0xCC,0xCF,	// symbol '['
  0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x02,	// symbol '\'
  0xF3,0x33,0x33,0x33,0x3F,	// symbol ']'
  0x10,0x71,0xB6,0x30,	// symbol '^'
  0xFF,	// symbol '_'
  0xD9,0x80,	// symbol '`'
  0x78,0x19,0xF6,0x6C,0xD9,0x9D,0x80,	// eng 'a'
  0xE0,0xC1,0x83,0xC6,0xCC,0xD9,0xB3,0x67,0xB8,	// eng 'b'
  0x7D,0x8F,0x06,0x0C,0x18,0xDF,0x00,	// eng 'c'
  0x1C,0x18,0x31,0xE6,0xD9,0xB3,0x66,0xCC,0xEC,	// eng 'd'
  0x7D,0x8F,0xFE,0x0C,0x18,0xDF,0x00,	// eng 'e'
  0x39,0xB6,0x58,0xF1,0x86,0x18,0x63,0xC0,	// eng 'f'
  0x77,0x9B,0x36,0x6C,0xD9,0x9F,0x06,0xCC,0xF0,	// eng 'g'
  0xE0,0xC1,0x83,0x67,0x6C,0xD9,0xB3,0x67,0xCC,	// eng 'h'
  0x66,0x0E,0x66,0x66,0x6F,	// eng 'i'
  0x0C,0x30,0x07,0x0C,0x30,0xC3,0x0C,0x3C,0xF3,0x78,	// eng 'j'
  0xE0,0xC1,0x83,0x36,0xCF,0x1E,0x36,0x67,0xCC,	// eng 'k'
  0xE6,0x66,0x66,0x66,0x6F,	// eng 'l'
  0xED,0xFF,0x5E,0xBD,0x7A,0xF5,0x80,	// eng 'm'
  0xDC,0xCD,0x9B,0x36,0x6C,0xD9,0x80,	// eng 'n'
  0x7D,0x8F,0x1E,0x3C,0x78,0xDF,0x00,	// eng 'o'
  0xDC,0xCD,0x9B,0x36,0x6C,0xDF,0x30,0x61,0xE0,	// eng 'p'
  0x77,0x9B,0x36,0x6C,0xD9,0x9F,0x06,0x0C,0x3C,	// eng 'q'
  0xDC,0xED,0x8B,0x06,0x0C,0x3C,0x00,	// eng 'r'
  0x7D,0x8D,0x81,0xC0,0xD8,0xDF,0x00,	// eng 's'
  0x10,0x60,0xC7,0xE3,0x06,0x0C,0x18,0x36,0x38,	// eng 't'
  0xCD,0x9B,0x36,0x6C,0xD9,0x9D,0x80,	// eng 'u'
  0xCF,0x3C,0xF3,0xCD,0xE3,0x00,	// eng 'v'
  0xC7,0x8F,0x1E,0xBD,0x7F,0xDB,0x00,	// eng 'w'
  0xC6,0xD8,0xE1,0xC3,0x8D,0xB1,0x80,	// eng 'x'
  0xC7,0x8F,0x1E,0x3C,0x78,0xDF,0x83,0x0D,0xF0,	// eng 'y'
  0xFF,0x98,0x61,0x86,0x18,0xFF,0x80,	// eng 'z'
  0x1C,0xC3,0x0C,0xE0,0xC3,0x0C,0x30,0x70,	// symbol '{'
  0xFF,0x3F,0xF0,	// symbol '|'
  0xE0,0xC3,0x0C,0x1C,0xC3,0x0C,0x33,0x80,	// symbol '}'
  0x77,0xB8,	// symbol '~'
  0x10,0x71,0xB6,0x3C,0x78,0xFF,0x80,	// DEL
  0x1E,0x6D,0x9E,0x3C,0x7F,0xF1,0xE3,0xC7,0x8C,	// symbol 'Ђ'
  0xFE,0xC5,0x8B,0x07,0xCC,0xD9,0xB3,0x67,0xF8,	// symbol 'Ѓ'
  0xFC,0xCD,0x9B,0x37,0xCC,0xD9,0xB3,0x67,0xF8,	// symbol '‚'
  0xFE,0xC5,0x8B,0x06,0x0C,0x18,0x30,0x61,0xE0,	// symbol 'ѓ'
  0x1E,0x36,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0xFF,0xC3,0x81,	// symbol '„'
  0xFE,0xCD,0x8B,0x47,0x8D,0x18,0x31,0x67,0xFC,	// symbol '…'
  0xD7,0xAD,0x52,0xA7,0xCF,0x95,0x6B,0xD7,0xAC,	// symbol '†'
  0x7D,0x8C,0x18,0x33,0xC0,0xC1,0x83,0xC6,0xF8,	// symbol '‡'
  0xC7,0x8F,0x3E,0x7D,0x7C,0xF9,0xE3,0xC7,0x8C,	// symbol '€'
  0x38,0x73,0x1E,0x3C,0xF9,0xF5,0xF3,0xE7,0x8F,0x1E,0x30,	// symbol '‰'
  0xE6,0xCD,0xB3,0x67,0x8F,0x1B,0x36,0x67,0xCC,	// symbol 'Љ'
  0x1E,0x6D,0x9E,0x3C,0x78,0xF1,0xE3,0xC7,0x8C,	// symbol '‹'
  0xC7,0xDF,0xFF,0xFD,0x78,0xF1,0xE3,0xC7,0x8C,	// symbol 'Њ'
  0xC7,0x8F,0x1E,0x3F,0xF8,0xF1,0xE3,0xC7,0x8C,	// symbol 'Ќ'
  0x7D,0x8F,0x1E,0x3C,0x78,0xF1,0xE3,0xC6,0xF8,	// symbol 'Ћ'
  0xFF,0x8F,0x1E,0x3C,0x78,0xF1,0xE3,0xC7,0x8C,	// symbol 'Џ'
  0xFC,0xCD,0x9B,0x37,0xCC,0x18,0x30,0x61,0xE0,	// symbol 'ђ'
  0x3C,0xCF,0x0E,0x0C,0x18,0x30,0x61,0x66,0x78,	// symbol '‘'
  0xFE,0xD3,0x0C,0x30,0xC3,0x0C,0x31,0xE0,	// symbol '’'
  0xC7,0x8F,0x1E,0x3C,0x6F,0xC1,0x83,0xC6,0xF8,	// symbol '“'
  0x3C,0x18,0x7E,0xDB,0xDB,0xDB,0xDB,0xDB,0x7E,0x18,0x3C,	// symbol '”'
  0xC7,0x8D,0xB3,0xE3,0x87,0x1F,0x36,0xC7,0x8C,	// symbol '•'
  0xCD,0x9B,0x36,0x6C,0xD9,0xB3,0x66,0xCD,0xFC,0x18,0x30,	// symbol '–'
  0xC7,0x8F,0x1E,0x3C,0x6F,0xC1,0x83,0x06,0x0C,	// symbol '—'
  0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xFF,	// symbol '~'
  0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xFF,0x03,0x03,	// symbol '™'
  0xF8,0xB0,0x30,0x30,0x3E,0x33,0x33,0x33,0x33,0x7E,	// symbol 'љ'
  0xC3,0xC3,0xC3,0xC3,0xF3,0xDB,0xDB,0xDB,0xDB,0xF3,	// symbol '›'
  0xF0,0xC1,0x83,0x07,0xCC,0xD9,0xB3,0x67,0xF8,	// symbol 'њ'
  0x7D,0x8C,0x19,0x33,0xE4,0xC1,0x83,0xC6,0xF8,	// symbol 'ќ'
  0xCE,0xDB,0xDB,0xDB,0xFB,0xDB,0xDB,0xDB,0xDB,0xCE,	// symbol 'ћ'
  0x3F,0x66,0x66,0x66,0x3E,0x3E,0x66,0x66,0x66,0xE7,	// symbol 'џ'
  0x78,0x19,0xF6,0x6C,0xD9,0x9D,0x80,	// char '160'
  0x04,0x37,0xB0,0xC3,0xEC,0xF3,0xCF,0x37,0x80,	// symbol 'Ў'
  0xFC,0xCD,0x9B,0xE6,0x6C,0xFF,0x00,	// symbol 'ў'
  0xFD,0x96,0x58,0x61,0x8F,0x00,	// symbol 'Ј'
  0x1E,0x36,0x36,0x66,0x66,0x66,0xFF,0xC3,0xC3,	// symbol '¤'
  0x7D,0x8F,0xFE,0x0C,0x18,0xDF,0x00,	// symbol 'Ґ'
  0xD7,0xAD,0x53,0xE5,0x5A,0xF5,0x80,	// symbol '¦'
  0x7B,0x30,0xC6,0x0F,0x37,0x80,	// symbol '§'
  0xC7,0x8F,0x3E,0xBE,0x78,0xF1,0x80,	// rus 'Ё'
  0x38,0x73,0x1E,0x3C,0xFA,0xF9,0xE3,0xC6,	// symbol '©'
  0xE6,0xD9,0xE3,0xC6,0xCC,0xF9,0x80,	// symbol 'Є'
  0x3D,0xBC,0xF3,0xCF,0x3C,0xC0,	// symbol '«'
  0xC7,0xDF,0xFF,0xFD,0x7A,0xF1,0x80,	// symbol '¬'
  0xC7,0x8F,0x1F,0xFC,0x78,0xF1,0x80,	// char '173'
  0x7D,0x8F,0x1E,0x3C,0x78,0xDF,0x00,	// symbol '®'
  0xFF,0x8F,0x1E,0x3C,0x78,0xF1,0x80,	// symbol 'Ї'
  0x23,0x10,0x8C,0x42,0x31,0x08,0xC4,0x23,0x10,0x8C,0x42,0x31,0x08,0xC4,	// symbol '°'
  0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,	// symbol '±'
  0xDD,0x77,0xDD,0x77,0xDD,0x77,0xDD,0x77,0xDD,0x77,0xDD,0x77,0xDD,0x77,0xDD,0x77,	// symbol 'І'
  0xFF,0xFF,0xFF,0xFF,	// symbol 'і'
  0x18,0xC6,0x31,0x8C,0x7F,0x18,0xC6,0x31,0x8C,0x63,	// symbol 'ґ'
  0x18,0xC6,0x31,0xFC,0x7F,0x18,0xC6,0x31,0x8C,0x63,	// symbol 'µ'
  0x36,0x6C,0xD9,0xB3,0x66,0xCD,0xFB,0x36,0x6C,0xD9,0xB3,0x66,0xCD,0x9B,	// symbol '¶'
  0xFE,0x6C,0xD9,0xB3,0x66,0xCD,0x9B,0x36,	// symbol '·'
  0xF8,0xFE,0x31,0x8C,0x63,0x18,0xC6,	// rus 'ё'
  0x36,0x6C,0xD9,0xB3,0x7E,0xC1,0xFB,0x36,0x6C,0xD9,0xB3,0x66,0xCD,0x9B,	// symbol '№'
  0xDE,0xF7,0xBD,0xEF,0x7B,0xDE,0xF7,0xBD,0xEF,0x7B,	// symbol 'є'
  0xFE,0x0F,0xD9,0xB3,0x66,0xCD,0x9B,0x36,0x6C,0xD8,	// symbol '»'
  0x36,0x6C,0xD9,0xB3,0x7E,0xC1,0xFF,	// symbol 'ј'
  0x36,0x6C,0xD9,0xB3,0x66,0xCD,0xFF,	// symbol 'Ѕ'
  0x18,0xC6,0x31,0xFC,0x7F,	// symbol 'ѕ'
  0xF8,0xC6,0x31,0x8C,0x63,0x18,	// symbol 'ї'
  0xC6,0x31,0x8C,0x63,0x1F,	// rus 'А'
  0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xFF,	// rus 'Б'
  0xFF,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,	// rus 'В'
  0xC6,0x31,0x8C,0x63,0x1F,0xC6,0x31,0x8C,0x63,0x18,	// rus 'Г'
  0xFF,	// rus 'Д'
  0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xFF,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,	// rus 'Е'
  0xC6,0x31,0x8C,0x7F,0x1F,0xC6,0x31,0x8C,0x63,0x18,	// rus 'Ж'
  0xDB,0x6D,0xB6,0xDB,0x6D,0xB7,0xDB,0x6D,0xB6,0xDB,0x6D,0xB6,	// rus 'З'
  0xDB,0x6D,0xB6,0xDB,0x7C,0x3F,	// rus 'И'
  0xFF,0x0D,0xF6,0xDB,0x6D,0xB6,0xDB,0x6D,0x80,	// rus 'Й'
  0x36,0x36,0x36,0x36,0x36,0xF7,0x00,0xFF,	// rus 'К'
  0xFF,0x00,0xF7,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x36,	// rus 'Л'
  0xDB,0x6D,0xB6,0xDB,0x7C,0x37,0xDB,0x6D,0xB6,0xDB,0x6D,0xB6,	// rus 'М'
  0xFF,0x00,0xFF,	// rus 'Н'
  0x36,0x36,0x36,0x36,0x36,0xF7,0x00,0xF7,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x36,	// rus 'О'
  0x18,0x18,0x18,0x18,0x18,0xFF,0x00,0xFF,	// rus 'П'
  0x36,0x36,0x36,0x36,0x36,0x36,0x36,0xFF,	// rus 'Р'
  0xFF,0x00,0xFF,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,	// rus 'С'
  0xFF,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x36,	// rus 'Т'
  0xDB,0x6D,0xB6,0xDB,0x6D,0xBF,	// rus 'У'
  0xC6,0x31,0x8C,0x7F,0x1F,	// rus 'Ф'
  0xFE,0x3F,0x8C,0x63,0x18,0xC6,0x30,	// rus 'Х'
  0xFF,0x6D,0xB6,0xDB,0x6D,0xB6,0xD8,	// rus 'Ц'
  0x36,0x36,0x36,0x36,0x36,0x36,0x36,0xFF,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x36,	// rus 'Ч'
  0x18,0x18,0x18,0x18,0x18,0xFF,0x18,0xFF,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,	// rus 'Ш'
  0x18,0xC6,0x31,0x8C,0x7F,	// rus 'Щ'
  0xFE,0x31,0x8C,0x63,0x18,0xC0,	// rus 'Ъ'
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,	// rus 'Ы'
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,	// rus 'Ь'
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,	// rus 'Э'
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,	// rus 'Ю'
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,	// rus 'Я'
  0xDC,0xCD,0x9B,0x36,0x6C,0xDF,0x30,0x61,0xE0,	// rus 'а'
  0x7D,0x8F,0x06,0x0C,0x18,0xDF,0x00,	// rus 'б'
  0xFE,0xD3,0x0C,0x30,0xC7,0x80,	// rus 'в'
  0xC7,0x8F,0x1E,0x3C,0x6F,0xC1,0x83,0xC6,0xF8,	// rus 'г'
  0x3C,0x18,0x7E,0xDB,0xDB,0xDB,0xDB,0x7E,0x18,0x18,0x3C,	// rus 'д'
  0xC6,0xD8,0xE1,0xC3,0x8D,0xB1,0x80,	// rus 'е'
  0xCD,0x9B,0x36,0x6C,0xD9,0xBF,0x83,0x06,	// rus 'ж'
  0xC7,0x8F,0x1E,0x37,0xE0,0xC1,0x80,	// rus 'з'
  0xD7,0xAF,0x5E,0xBD,0x7A,0xFF,0x80,	// rus 'и'
  0xD6,0xD6,0xD6,0xD6,0xD6,0xD6,0xFE,0x03,0x03,	// rus 'й'
  0xF8,0xB0,0x30,0x3E,0x33,0x33,0x7E,	// rus 'к'
  0xC7,0x8F,0x1F,0xBD,0xFB,0xFD,0x80,	// rus 'л'
  0xF0,0xC1,0x83,0xE6,0x6C,0xFF,0x00,	// rus 'м'
  0x7B,0x30,0xCF,0x0F,0x37,0x80,	// rus 'н'
  0xCE,0xDB,0xDB,0xFB,0xDB,0xDB,0xCE,	// rus 'о'
  0x7F,0x9B,0x37,0xE6,0xD9,0xB3,0x80,	// rus 'п'
  0x6C,0x03,0xFB,0x36,0x2D,0x1E,0x34,0x60,0xC5,0x9F,0xF0,	// rus 'р'
  0x6C,0x01,0xF6,0x3F,0xF8,0x30,0x63,0x7C,	// rus 'с'
  0x7D,0x8F,0x06,0x4F,0x99,0x30,0x60,0xC6,0xF8,	// rus 'т'
  0x7B,0x3C,0x3C,0xC3,0x37,0x80,	// rus 'у'
  0xCC,0x07,0x8C,0x30,0xC3,0x0C,0x30,0xC3,0x1E,	// rus 'ф'
  0xAA,0x0E,0x66,0x66,0x6F,	// rus 'х'
  0x30,0xC0,0x3F,0x00,0xC3,0x00,	// rus 'ц'
  0x77,0xB8,0x03,0xBD,0xC0,	// rus 'ч'
  0x76,0xF6,0xE0,	// rus 'ш'
  0xF0,	// rus 'щ'
  0xC0,	// rus 'ъ'
  0x01,0x03,0x02,0x06,0x04,0xCC,0x68,0x38,0x10,	// rus 'ы'
  0x8B,0xCB,0xC8,0xA8,0xA8,0x98,0x98,0x88,0x88,	// rus 'ь'
  0x76,0xCC,0xCC,0xFC,	// rus 'э'
  0xFF,0xFF,0xFF,	// rus 'ю'
};

const GFXglyph RusFontGlyphs[] PROGMEM = {
  { 0, 0, 0, 5, 0, 0 },	// NUL
  { 0, 8, 10, 8, 0, -13 },	// SOH
  { 10, 8, 10, 8, 0, -13 },	// STX
  { 20, 7, 8, 8, 0, -11 },	// ETX
  { 27, 7, 7, 8, 0, -11 },	// EOT
  { 34, 8, 9, 8, 0, -12 },	// ENQ
  { 43, 8, 9, 8, 0, -12 },	// ACK
  { 52, 4, 4, 7, 2, -9 },	// BEL
  { 54, 8, 16, 8, 0, -15 },	// BS
  { 70, 6, 6, 8, 1, -10 },	// TAB
  { 75, 8, 16, 8, 0, -15 },	// LF
  { 91, 7, 10, 8, 0, -13 },	// VT
  { 100, 6, 10, 8, 1, -13 },	// FF
  { 108, 8, 10, 8, 0, -13 },	// CR
  { 118, 8, 11, 8, 0, -13 },	// SO
  { 129, 8, 9, 8, 0, -12 },	// SI
  { 138, 7, 11, 8, 0, -14 },	// DLE
  { 148, 7, 11, 8, 0, -14 },	// DC1
  { 158, 6, 10, 8, 1, -13 },	// DC2
  { 166, 6, 10, 8, 1, -13 },	// DC3
  { 174, 8, 10, 8, 0, -13 },	// DC4
  { 184, 7, 12, 8, 0, -14 },	// NAK
  { 195, 7, 4, 8, 0, -7 },	// SYN
  { 199, 6, 11, 8, 1, -13 },	// ETB
  { 208, 6, 10, 8, 1, -13 },	// CAN
  { 216, 6, 10, 8, 1, -13 },	// EM
  { 224, 7, 5, 8, 0, -10 },	// SUB
  { 229, 7, 5, 8, 0, -10 },	// ESC
  { 234, 7, 5, 8, 0, -10 },	// FS
  { 239, 7, 5, 8, 0, -10 },	// GS
  { 244, 7, 7, 8, 0, -11 },	// RS
  { 251, 7, 7, 8, 0, -11 },	// US
  { 258, 0, 0, 5, 0, 0 },	// SPC
  { 258, 4, 10, 7, 2, -13 },	// symbol '!'
  { 263, 6, 4, 8, 1, -14 },	// symbol
  { 266, 7, 9, 8, 0, -12 },	// symbol '#'
  { 274, 7, 13, 8, 0, -15 },	// symbol '$'
  { 286, 7, 8, 8, 0, -11 },	// symbol '%'
  { 293, 7, 10, 8, 0, -13 },	// symbol '&'
  { 302, 3, 4, 5, 1, -14 },	// symbol '''
  { 304, 4, 10, 7, 2, -13 },	// symbol '('
  { 309, 4, 10, 7, 2, -13 },	// symbol ')'
  { 314, 8, 5, 8, 0, -10 },	// symbol '*'
  { 319, 6, 5, 8, 1, -10 },	// symbol '+'
  { 323, 3, 4, 6, 2, -6 },	// symbol ','
  { 325, 7, 1, 8, 0, -8 },	// symbol '-'
  { 326, 2, 2, 6, 3, -5 },	// symbol '.'
  { 327, 7, 8, 8, 0, -11 },	// symbol '/'
  { 334, 7, 10, 8, 0, -13 },	// digit '0'
  { 343, 6, 10, 8, 1, -13 },	// digit '1'
  { 351, 7, 10, 8, 0, -13 },	// digit '2'
  { 360, 7, 10, 8, 0, -13 },	// digit '3'
  { 369, 7, 10, 8, 0, -13 },	// digit '4'
  { 378, 7, 10, 8, 0, -13 },	// digit '5'
  { 387, 7, 10, 8, 0, -13 },	// digit '6'
  { 396, 7, 10, 8, 0, -13 },	// digit '7'
  { 405, 7, 10, 8, 0, -13 },	// digit '8'
  { 414, 7, 10, 8, 0, -13 },	// digit '9'
  { 423, 2, 7, 6, 3, -11 },	// symbol ':'
  { 425, 3, 8, 6, 2, -11 },	// symbol ';'
  { 428, 6, 9, 8, 1, -12 },	// symbol '<'
  { 435, 7, 4, 8, 0, -9 },	// symbol '='
  { 439, 6, 9, 8, 1, -12 },	// symbol '>'
  { 446, 7, 10, 8, 0, -13 },	// symbol '?'
  { 455, 7, 9, 8, 0, -12 },	// symbol '@'
  { 463, 7, 10, 8, 0, -13 },	// eng 'A'
  { 472, 7, 10, 8, 0, -13 },	// eng 'B'
  { 481, 7, 10, 8, 0, -13 },	// eng 'C'
  { 490, 7, 10, 8, 0, -13 },	// eng 'D'
  { 499, 7, 10, 8, 0, -13 },	// eng 'E'
  { 508, 7, 10, 8, 0, -13 },	// eng 'F'
  { 517, 7, 10, 8, 0, -13 },	// eng 'G'
  { 526, 7, 10, 8, 0, -13 },	// eng 'H'
  { 535, 4, 10, 7, 2, -13 },	// eng 'I'
  { 540, 7, 10, 8, 0, -13 },	// eng 'J'
  { 549, 7, 10, 8, 0, -13 },	// eng 'K'
  { 558, 7, 10, 8, 0, -13 },	// eng 'L'
  { 567, 7, 10, 8, 0, -13 },	// eng 'M'
  { 576, 7, 10, 8, 0, -13 },	// eng 'N'
  { 585, 7, 10, 8, 0, -13 },	// eng 'O'
  { 594, 7, 10, 8, 0, -13 },	// eng 'P'
  { 603, 7, 12, 8, 0, -13 },	// eng 'Q'
  { 614, 7, 10, 8, 0, -13 },	// eng 'R'
  { 623, 7, 10, 8, 0, -13 },	// eng 'S'
  { 632, 6, 10, 8, 1, -13 },	// eng 'T'
  { 640, 7, 10, 8, 0, -13 },	// eng 'U'
  { 649, 7, 10, 8, 0, -13 },	// eng 'V'
  { 658, 7, 10, 8, 0, -13 },	// eng 'W'
  { 667, 7, 10, 8, 0, -13 },	// eng 'X'
  { 676, 6, 10, 8, 1, -13 },	// eng 'Y'
  { 684, 7, 10, 8, 0, -13 },	// eng 'Z'
  { 693, 4, 10, 7, 2, -13 },	// symbol '['
  { 698, 7, 9, 8, 0, -12 },	// symbol '\'
  { 706, 4, 10, 7, 2, -13 },	// symbol ']'
  { 711, 7, 4, 8, 0, -15 },	// symbol '^'
  { 715, 8, 1, 8, 0, -2 },	// symbol '_'
  { 716, 3, 3, 6, 2, -15 },	// symbol '`'
  { 718, 7, 7, 8, 0, -10 },	// eng 'a'
  { 725, 7, 10, 8, 0, -13 },	// eng 'b'
  { 734, 7, 7, 8, 0, -10 },	// eng 'c'
  { 741, 7, 10, 8, 0, -13 },	// eng 'd'
  { 750, 7, 7, 8, 0, -10 },	// eng 'e'
  { 757, 6, 10, 7, 0, -13 },	// eng 'f'
  { 765, 7, 10, 8, 0, -10 },	// eng 'g'
  { 774, 7, 10, 8, 0, -13 },	// eng 'h'
  { 783, 4, 10, 7, 2, -13 },	// eng 'i'
  { 788, 6, 13, 8, 1, -13 },	// eng 'j'
  { 798, 7, 10, 8, 0, -13 },	// eng 'k'
  { 807, 4, 10, 7, 2, -13 },	// eng 'l'
  { 812, 7, 7, 8, 0, -10 },	// eng 'm'
  { 819, 7, 7, 8, 0, -10 },	// eng 'n'
  { 826, 7, 7, 8, 0, -10 },	// eng 'o'
  { 833, 7, 10, 8, 0, -10 },	// eng 'p'
  { 842, 7, 10, 8, 0, -10 },	// eng 'q'
  { 851, 7, 7, 8, 0, -10 },	// eng 'r'
  { 858, 7, 7, 8, 0, -10 },	// eng 's'
  { 865, 7, 10, 8, 0, -13 },	// eng 't'
  { 874, 7, 7, 8, 0, -10 },	// eng 'u'
  { 881, 6, 7, 8, 1, -10 },	// eng 'v'
  { 887, 7, 7, 8, 0, -10 },	// eng 'w'
  { 894, 7, 7, 8, 0, -10 },	// eng 'x'
  { 901, 7, 10, 8, 0, -10 },	// eng 'y'
  { 910, 7, 7, 8, 0, -10 },	// eng 'z'
  { 917, 6, 10, 8, 1, -13 },	// symbol '{'
  { 925, 2, 10, 6, 3, -13 },	// symbol '|'
  { 928, 6, 10, 8, 1, -13 },	// symbol '}'
  { 936, 7, 2, 8, 0, -13 },	// symbol '~'
  { 938, 7, 7, 8, 0, -11 },	// DEL
  { 945, 7, 10, 8, 0, -13 },	// symbol 'Ђ'
  { 954, 7, 10, 8, 0, -13 },	// symbol 'Ѓ'
  { 963, 7, 10, 8, 0, -13 },	// symbol '‚'
  { 972, 7, 10, 8, 0, -13 },	// symbol 'ѓ'
  { 981, 8, 12, 8, 0, -13 },	// symbol '„'
  { 993, 7, 10, 8, 0, -13 },	// symbol '…'
  { 1002, 7, 10, 8, 0, -13 },	// symbol '†'
  { 1011, 7, 10, 8, 0, -13 },	// symbol '‡'
  { 1020, 7, 10, 8, 0, -13 },	// symbol '€'
  { 1029, 7, 12, 8, 0, -15 },	// symbol '‰'
  { 1040, 7, 10, 8, 0, -13 },	// symbol 'Љ'
  { 1049, 7, 10, 8, 0, -13 },	// symbol '‹'
  { 1058, 7, 10, 8, 0, -13 },	// symbol 'Њ'
  { 1067, 7, 10, 8, 0, -13 },	// symbol 'Ќ'
  { 1076, 7, 10, 8, 0, -13 },	// symbol 'Ћ'
  { 1085, 7, 10, 8, 0, -13 },	// symbol 'Џ'
  { 1094, 7, 10, 8, 0, -13 },	// symbol 'ђ'
  { 1103, 7, 10, 8, 0, -13 },	// symbol '‘'
  { 1112, 6, 10, 8, 1, -13 },	// symbol '’'
  { 1120, 7, 10, 8, 0, -13 },	// symbol '“'
  { 1129, 8, 11, 8, 0, -14 },	// symbol '”'
  { 1140, 7, 10, 8, 0, -13 },	// symbol '•'
  { 1149, 7, 12, 8, 0, -13 },	// symbol '–'
  { 1160, 7, 10, 8, 0, -13 },	// symbol '—'
  { 1169, 8, 10, 8, 0, -13 },	// symbol '~'
  { 1179, 8, 12, 8, 0, -13 },	// symbol '™'
  { 1191, 8, 10, 8, 0, -13 },	// symbol 'љ'
  { 1201, 8, 10, 8, 0, -13 },	// symbol '›'
  { 1211, 7, 10, 8, 0, -13 },	// symbol 'њ'
  { 1220, 7, 10, 8, 0, -13 },	// symbol 'ќ'
  { 1229, 8, 10, 8, 0, -13 },	// symbol 'ћ'
  { 1239, 8, 10, 8, 0, -13 },	// symbol 'џ'
  { 1249, 7, 7, 8, 0, -10 },	// char '160'
  { 1256, 6, 11, 8, 1, -14 },	// symbol 'Ў'
  { 1265, 7, 7, 8, 0, -10 },	// symbol 'ў'
  { 1272, 6, 7, 8, 1, -10 },	// symbol 'Ј'
  { 1278, 8, 9, 8, 0, -10 },	// symbol '¤'
  { 1287, 7, 7, 8, 0, -10 },	// symbol 'Ґ'
  { 1294, 7, 7, 8, 0, -10 },	// symbol '¦'
  { 1301, 6, 7, 8, 1, -10 },	// symbol '§'
  { 1307, 7, 7, 8, 0, -10 },	// rus 'Ё'
  { 1314, 7, 9, 8, 0, -12 },	// symbol '©'
  { 1322, 7, 7, 8, 0, -10 },	// symbol 'Є'
  { 1329, 6, 7, 8, 1, -10 },	// symbol '«'
  { 1335, 7, 7, 8, 0, -10 },	// symbol '¬'
  { 1342, 7, 7, 8, 0, -10 },	// char '173'
  { 1349, 7, 7, 8, 0, -10 },	// symbol '®'
  { 1356, 7, 7, 8, 0, -10 },	// symbol 'Ї'
  { 1363, 7, 16, 8, 1, -15 },	// symbol '°'
  { 1377, 8, 16, 8, 0, -15 },	// symbol '±'
  { 1393, 8, 16, 8, 0, -15 },	// symbol 'І'
  { 1409, 2, 16, 6, 3, -15 },	// symbol 'і'
  { 1413, 5, 16, 6, 0, -15 },	// symbol 'ґ'
  { 1423, 5, 16, 6, 0, -15 },	// symbol 'µ'
  { 1433, 7, 16, 8, 0, -15 },	// symbol '¶'
  { 1447, 7, 9, 8, 0, -8 },	// symbol '·'
  { 1455, 5, 11, 6, 0, -10 },	// rus 'ё'
  { 1462, 7, 16, 8, 0, -15 },	// symbol '№'
  { 1476, 5, 16, 8, 2, -15 },	// symbol 'є'
  { 1486, 7, 11, 8, 0, -10 },	// symbol '»'
  { 1496, 7, 8, 8, 0, -15 },	// symbol 'ј'
  { 1503, 7, 8, 8, 0, -15 },	// symbol 'Ѕ'
  { 1510, 5, 8, 6, 0, -15 },	// symbol 'ѕ'
  { 1515, 5, 9, 6, 0, -8 },	// symbol 'ї'
  { 1521, 5, 8, 8, 3, -15 },	// rus 'А'
  { 1526, 8, 8, 8, 0, -15 },	// rus 'Б'
  { 1534, 8, 9, 8, 0, -8 },	// rus 'В'
  { 1543, 5, 16, 8, 3, -15 },	// rus 'Г'
  { 1553, 8, 1, 8, 0, -8 },	// rus 'Д'
  { 1554, 8, 16, 8, 0, -15 },	// rus 'Е'
  { 1570, 5, 16, 8, 3, -15 },	// rus 'Ж'
  { 1580, 6, 16, 8, 2, -15 },	// rus 'З'
  { 1592, 6, 8, 8, 2, -15 },	// rus 'И'
  { 1598, 6, 11, 8, 2, -10 },	// rus 'Й'
  { 1607, 8, 8, 8, 0, -15 },	// rus 'К'
  { 1615, 8, 11, 8, 0, -10 },	// rus 'Л'
  { 1626, 6, 16, 8, 2, -15 },	// rus 'М'
  { 1638, 8, 3, 8, 0, -10 },	// rus 'Н'
  { 1641, 8, 16, 8, 0, -15 },	// rus 'О'
  { 1657, 8, 8, 8, 0, -15 },	// rus 'П'
  { 1665, 8, 8, 8, 0, -15 },	// rus 'Р'
  { 1673, 8, 11, 8, 0, -10 },	// rus 'С'
  { 1684, 8, 9, 8, 0, -8 },	// rus 'Т'
  { 1693, 6, 8, 8, 2, -15 },	// rus 'У'
  { 1699, 5, 8, 8, 3, -15 },	// rus 'Ф'
  { 1704, 5, 11, 8, 3, -10 },	// rus 'Х'
  { 1711, 6, 9, 8, 2, -8 },	// rus 'Ц'
  { 1718, 8, 16, 8, 0, -15 },	// rus 'Ч'
  { 1734, 8, 16, 8, 0, -15 },	// rus 'Ш'
  { 1750, 5, 8, 6, 0, -15 },	// rus 'Щ'
  { 1755, 5, 9, 8, 3, -8 },	// rus 'Ъ'
  { 1761, 8, 16, 8, 0, -15 },	// rus 'Ы'
  { 1777, 8, 9, 8, 0, -8 },	// rus 'Ь'
  { 1786, 4, 16, 5, 0, -15 },	// rus 'Э'
  { 1794, 4, 16, 8, 4, -15 },	// rus 'Ю'
  { 1802, 8, 7, 8, 0, -15 },	// rus 'Я'
  { 1809, 7, 10, 8, 0, -10 },	// rus 'а'
  { 1818, 7, 7, 8, 0, -10 },	// rus 'б'
  { 1825, 6, 7, 8, 1, -10 },	// rus 'в'
  { 1831, 7, 10, 8, 0, -10 },	// rus 'г'
  { 1840, 8, 11, 8, 0, -11 },	// rus 'д'
  { 1851, 7, 7, 8, 0, -10 },	// rus 'е'
  { 1858, 7, 9, 8, 0, -10 },	// rus 'ж'
  { 1866, 7, 7, 8, 0, -10 },	// rus 'з'
  { 1873, 7, 7, 8, 0, -10 },	// rus 'и'
  { 1880, 8, 9, 8, 0, -10 },	// rus 'й'
  { 1889, 8, 7, 8, 0, -10 },	// rus 'к'
  { 1896, 7, 7, 8, 0, -10 },	// rus 'л'
  { 1903, 7, 7, 8, 0, -10 },	// rus 'м'
  { 1910, 6, 7, 8, 1, -10 },	// rus 'н'
  { 1916, 8, 7, 8, 0, -10 },	// rus 'о'
  { 1923, 7, 7, 8, 0, -10 },	// rus 'п'
  { 1930, 7, 12, 8, 0, -15 },	// rus 'р'
  { 1941, 7, 9, 8, 0, -12 },	// rus 'с'
  { 1949, 7, 10, 8, 0, -13 },	// rus 'т'
  { 1958, 6, 7, 8, 1, -10 },	// rus 'у'
  { 1964, 6, 12, 8, 1, -15 },	// rus 'ф'
  { 1973, 4, 10, 7, 2, -13 },	// rus 'х'
  { 1978, 6, 7, 8, 1, -11 },	// rus 'ц'
  { 1984, 7, 5, 8, 0, -10 },	// rus 'ч'
  { 1989, 5, 4, 7, 1, -14 },	// rus 'ш'
  { 1992, 2, 2, 6, 3, -8 },	// rus 'щ'
  { 1993, 2, 1, 6, 3, -7 },	// rus 'ъ'
  { 1994, 8, 9, 8, 0, -12 },	// rus 'ы'
  { 2003, 8, 9, 8, 0, -12 },	// rus 'ь'
  { 2012, 5, 6, 6, 0, -14 },	// rus 'э'
  { 2016, 4, 6, 7, 2, -10 },	// rus 'ю'
  { 2019, 0, 0, 5, 0, 0 }	// rus 'я'
};

const GFXfont RusFont PROGMEM = {
 (uint8_t *)RusFontBitmaps,
 (GFXglyph *)RusFontGlyphs,
 0, 255, 16};
