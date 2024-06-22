# rp2040_rotary

Seeed Xiao RP2040でロータリエンコーダーを使った試作

![試作](./images/image001.jpg)

## wslでのコンパイル＆インストール
### コンパイル
```
qmk compile -kb rp2040_rotary -km default
```

### インストール
#### Windowsファイルシステムへ移動
```
mv *.uf2 /mnt/d/_t/kbd
```

#### 書き込み
- Seeed Xiao RP2040のブートボタンを押しながらUSB接続する
    - もしくは、USB接続した上で、ブートボタンを押しながらリセットボタンを押す
- マイコンピュータでSeeed Xiao RP2040を開き、ファームウェア（uf2ファイル）をコピーする