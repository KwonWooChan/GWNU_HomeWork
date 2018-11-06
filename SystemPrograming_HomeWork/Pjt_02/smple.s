5    COPY     START   1000
10    FIRST    STL     RETADR
15    CLOOP    JSUB    RDREC
20             LDA     LENGTH
25             COMP    ZERO
30             JEQ     ENDFIL
35             JSUB    WRREC
40             J       CLOOP
45    ENDFIL   LDA     EOF
50             STA     BUFFER
55             LDA     THREE
60             STA     LENGTH
65             JSUB    WRREC
70             LDA     RETADR
75             RSUB
80    EOF      BYTE    C'EOF'
85    THREE    WORD    3
90    ZERO     WORD    0
95    RETADR   RESW    1
100    LENGTH   RESW    1
105    BUFFER   RESB    4096
125   RDREC    LDX     ZERO
130             LDA     ZERO
135    RLOOP    TD      INPUT
140             JEQ     TLOOP
145             RD      INPUT
150             COMP    ZERO
155             JEQ     EXIT
160             STCH    BUFFER,X
165             TIX     MAXLEN
170             JLT     RLOOP
175    EXIT     STX     LENGTH
180             RSUB
185    INPUT    BYTE    X'F1'
190    MAXLEN   WORD    4096
210    WRREC    LDX     ZERO
215    WLOOP    TD      OUTPUT
220            JEQ     WLOOP
225             LDCH    BUFFER,X
230             WD      OUTPUT
235             TIX     LENGTH
240             JLT     WLOOP
245             RSUB
250    OUTPUT   BYTE    X'05'
255             END     FIRST