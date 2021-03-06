import addon from "./utils/addon";
import {
  NativeElement,
  Component,
  QUrl,
} from "@nodegui/nodegui";

/**
 
> The QMediaContent class provides access to the resource relating to a media content.

* **This class is a JS wrapper around Qt's [QMediaContent class](https://doc.qt.io/qt-5/qmediacontent.html)**

A `QMediaContent` provides ability to store an image in the memory.

### Example

```javascript
const { QMediaContent } = require("nodegui-plugin-qtmultimedia");

const mediaContent = new QMediaContent();
```
 */
export class QMediaPlayer extends Component {
  native: NativeElement;
  constructor() {
    super();
    this.native = new addon.QMediaPlayer();
  }

  play(): void {
    return this.native.play();
  }

  setMedia(url: QUrl): void {
    return this.native.setMedia(url);
  }
}
