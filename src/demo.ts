import { QMainWindow } from "@nodegui/nodegui";
import { QMediaContent } from "./lib/QMediaContent";

const win = new QMainWindow();
const mcontent = new QMediaContent();
console.log("isNull", mcontent.isNull());
win.show();

(global as any).win = win; // To prevent win from being garbage collected.
