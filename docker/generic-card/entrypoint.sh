#! /bin/bash
set -e

# Add QTcreator alias command
if [ -d "$HOME/Qt" ]; then
	echo "alias qtcreator=$HOME/Qt/Tools/QtCreator/bin/qtcreator" >> $HOME/.bash_aliases
	echo "alias qtcreator=$HOME/Qt/Tools/QtCreator/bin/qtcreator" >> $HOME/.zshrc
fi

exec "$@"

