import { QMainWindow, QUrl } from "@nodegui/nodegui";
import { QMediaContent } from "./lib/QMediaContent";
import { QMediaPlayer } from "./lib/QMediaPlayer";

const win = new QMainWindow();
const mcontent = new QMediaContent();
const mplayer = new QMediaPlayer();
// mplayer.setMedia(new QUrl("file:///some/file.mp3"));
// mplayer.play();
console.log("isNull", mcontent.isNull());
win.show();

(global as any).win = win; // To prevent win from being garbage collected.
