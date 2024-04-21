# 自作キーボード設計入門２をやってみる
## 作業手順
1. qmk_firmwareのダウンロード
```
$ git clone --depth 1 -b 0.24.7 --recurse-submodules --shallow-submodules git@github.com:qmk/qmk_firmware.git
```

2. キーボードの追加
```
$ qmk new-keyboard
```
- キーボード名に適当な名前を指定
- github usernameとreal nameは適当に
- default layoutは、`none of the above`
- MCUは、`atmega32u4`（`promicro`でもよさそう）
    - `promicro`にしないと正しいブートローダー`caterina`にならなくて、flashできない

3. コンパイル
```
$ qmk compile -kb <2.でつけたキーボード名> -km default
```
- kmには、キーマップ名を指定する

4. ファームウェアの書き込み
- [Promicro Web Updater](https://sekigon-gonnoc.github.io/promicro-web-updater/index.html)を使う
- コマンドラインから
    - `qmk flash -kb <keyboard name> -km default`

## 参考
- [自作キーボード設計入門２を読みながらいろいろ試してみました](https://www.eisbahn.jp/yoichiro/2020/10/self_made_keyboard_design_book_2.html)
    - 必要な部品やその購入先とか
- [自作キーボード設計入門2 読書メモ](https://zenn.dev/goropikari/scraps/f973aceaa5cf37)
    - 2024.04時点でのqmk_firmwareを使ったやり方が載っている
- qmk_firmware document
    - [Syllabus](https://docs.qmk.fm/#/syllabus)
        - コンテンツ一覧的に使える
    - [info.json Reference](https://docs.qmk.fm/#/reference_info_json)
    - [Split Keyboard](https://docs.qmk.fm/#/feature_split_keyboard)
- [promicroの仕様](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/hardware-overview-pro-micro)
    - オリジナルのsparkfunのサイト
    - VCC, RAW, RST, GNDやI/Oピンの説明とかある
- [promicroのAVRアーキテクチャとしてのピン名とか](https://golem.hu/article/pro-micro-pinout/)
    - qmk_firmwareでは、AVRのピン名を使用するので助かる
