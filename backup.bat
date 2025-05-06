set -e
for i in $@; do
  FILENAME=$(echo $i | sed 's/\//-/g')
  echo "== Backing up $i to $FILENAME.bak"
  git clone git@github.com:$i $FILENAME.git --mirror
  cd "$FILENAME.git"
  git bundle create ../$FILENAME.bak --all
  cd ..
  rm -rf $i.git
  echo "== Repository saved as $FILENAME.bak"
PAUSE