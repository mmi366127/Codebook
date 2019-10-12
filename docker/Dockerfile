FROM ubuntu:18.04

#Install required packages
#Uncomment or comment out some lines to meet languages you're using.
RUN DEBIAN_FRONTEND=noninteractive apt-get update && apt-get install --no-install-recommends -y \
fontforge \
texlive-xetex \
git \
wget \
cabextract \
unzip \
openssl \
ca-certificates \
&& rm -rf /var/lib/apt/lists/*

COPY consolas.sh consolas.sh

RUN update-ca-certificates

RUN bash consolas.sh && rm consolas.sh

RUN wget -P /raw_fonts https://noto-website-2.storage.googleapis.com/pkgs/NotoSansCJKtc-hinted.zip --no-check-certificate && \
    cd /raw_fonts && \
    mkdir /usr/share/fonts/noto && \
    unzip -o NotoSansCJKtc-hinted.zip && \
    mv -t /usr/share/fonts/noto *-DemiLight.otf *-Bold.otf *-Black.otf && \
    rm -r /raw_fonts && \
    fc-cache -f -v

ENTRYPOINT ["/bin/bash"]
