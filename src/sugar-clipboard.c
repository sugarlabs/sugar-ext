/*
 * Copyright (C) 2014, Martin Abente Lahaye - tch@sugarlabs.org
 * Copyright (C) 2025, Chihurumnaya Ibiam   - ibiam@sugarlabs.org
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "sugar-clipboard.h"

/**
 * sugar_clipboard_set_with_data:
 * @clipboard: a #GdkClipboard
 * @mime_type: MIME type of @data.
 * @data: a #GBytes holding the raw payload.
 *
 * Sets a new content provider on @clipboard advertising @mime_type.
 *
 * The clipboard claims the display's selection and notifies other
 * applications of the new contents. Returns %FALSE in the rare case
 * where the display rejects the new owner; the clipboard then continues
 * to report its previous contents.
 *
 * Return value: %TRUE if setting the clipboard data succeeded.
 **/

gboolean
sugar_clipboard_set_with_data (GdkClipboard *clipboard,
                               const gchar  *mime_type,
                               GBytes       *data)
{
    GdkContentProvider *provider;
    gboolean ret;

    g_return_val_if_fail (GDK_IS_CLIPBOARD (clipboard), FALSE);
    g_return_val_if_fail (mime_type != NULL, FALSE);
    g_return_val_if_fail (data != NULL, FALSE);

    provider = gdk_content_provider_new_for_bytes (mime_type, data);
    ret = gdk_clipboard_set_content (clipboard, provider);
    g_object_unref (provider);

    return ret;
}
